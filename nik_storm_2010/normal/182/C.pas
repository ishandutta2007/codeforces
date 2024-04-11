uses math; const mm=400000;
var
  h1,h2:array[1..2,0..mm] of int64; a,p1,p2:array[0..mm] of int64;
  ans,cur,nom,num,s1,s2,n,l,k,x,y:int64; i:longint;


procedure clear;
begin
  s1:=0; s2:=0;
  fillchar(h1,sizeof(h1),0); fillchar(h2,sizeof(h2),0);
  fillchar(p1,sizeof(p1),0); fillchar(p2,sizeof(p2),0);
end;


procedure swap1(i,j:int64);
var w:int64;
begin
  p1[h1[2,i]]:=j; p1[h1[2,j]]:=i;
  w:=h1[1,i]; h1[1,i]:=h1[1,j]; h1[1,j]:=w;
  w:=h1[2,i]; h1[2,i]:=h1[2,j]; h1[2,j]:=w;
end;


procedure add1(nom,x:int64);
var i:int64;
begin
  inc(s1); h1[1,s1]:=x; h1[2,s1]:=nom; i:=s1; p1[nom]:=s1;
  while (i>1) and (h1[1,i]<h1[1,i div 2]) do
  begin
    swap1(i,i div 2); i:=i div 2;
  end;
end;


procedure del1(r:int64;var nom,x:int64);
var mi,no,i:int64;
begin
  nom:=h1[2,r]; x:=h1[1,r]; h1[1,r]:=0; h1[2,r]:=0;
  swap1(r,s1); p1[nom]:=0;
  dec(s1); i:=r;
  if r>s1 then exit;
  while (i*2<=s1) do
  begin
    mi:=h1[1,i*2]; no:=i*2;
    if (i*2+1<=s1) and (mi>h1[1,i*2+1]) then begin mi:=h1[1,i*2+1]; no:=i*2+1; end;
    if (h1[1,i]>mi) then begin swap1(i,no); i:=no; end else break;
  end;
  while (i>1) and (h1[1,i]<h1[1,i div 2]) do
  begin
    swap1(i,i div 2); i:=i div 2;
  end;
end;


procedure swap2(i,j:int64);
var w:int64;
begin
  p2[h2[2,i]]:=j; p2[h2[2,j]]:=i;
  w:=h2[1,i]; h2[1,i]:=h2[1,j]; h2[1,j]:=w;
  w:=h2[2,i]; h2[2,i]:=h2[2,j]; h2[2,j]:=w;
end;


procedure add2(nom,x:int64);
var i:int64;
begin
  inc(s2); h2[1,s2]:=x; h2[2,s2]:=nom; i:=s2; p2[nom]:=s2;
  while (i>1) and (h2[1,i]>h2[1,i div 2]) do
  begin
    swap2(i,i div 2); i:=i div 2;
  end;
end;


procedure del2(r:int64;var nom,x:int64);
var ma,no,i:int64;
begin
  nom:=h2[2,r]; x:=h2[1,r]; h2[1,r]:=0; h2[2,r]:=0;
  swap2(r,s2); p2[nom]:=0;
  dec(s2); i:=r;
  if r>s2 then exit;
  while (i*2<=s2) do
  begin
    ma:=h2[1,i*2]; no:=i*2;
    if (i*2+1<=s2) and (ma<h2[1,i*2+1]) then begin ma:=h2[1,i*2+1]; no:=i*2+1; end;
    if (h2[1,i]<ma) then begin swap2(i,no); i:=no; end else break;
  end;
  while (i>1) and (h2[1,i]>h2[1,i div 2]) do
  begin
    swap2(i,i div 2); i:=i div 2;
  end;
end;


begin

  readln(n,l);
  for i:=1 to n do read(a[i]); readln;
  readln(k);
  clear; cur:=0;
  for i:=1 to l do
  begin
    if a[i]<0 then add1(i,a[i]);
    cur:=cur+a[i];
  end;
  for i:=l+1 to n+1 do
  begin
    while s2<k do
    begin
      if s1=0 then break;
      del1(1,nom,x); add2(nom,x);
      cur:=cur-(x*2);
    end;
    if (s2>0) and (s2=k) and (s1>0) then
    begin
      while (h1[1,1]<h2[1,1]) do
      begin
        del1(1,nom,x); del2(1,num,y);
        add1(num,y); add2(nom,x);
        cur:=cur+(2*y)-(2*x);
      end;
    end;
    ans:=max(ans,abs(cur));
    if p1[i-l]<>0 then del1(p1[i-l],nom,x);
    if p2[i-l]<>0 then
    begin
      del2(p2[i-l],nom,x);
      cur:=cur+x;
    end
    else cur:=cur-a[i-l];
    if a[i]<0 then add1(i,a[i]);
    cur:=cur+a[i];
  end;
  clear; cur:=0;
  for i:=1 to l do
  begin
    if a[i]>0 then add2(i,a[i]);
    cur:=cur+a[i];
  end;
  for i:=l+1 to n+1 do
  begin
    while s1<k do
    begin
      if s2=0 then break;
      del2(1,nom,x); add1(nom,x);
      cur:=cur-(x*2);
    end;
    if (s2>0) and (s1=k) and (s1>0) then
    begin
      while (h1[1,1]<h2[1,1]) do
      begin
        del1(1,nom,x); del2(1,num,y);
        add1(num,y); add2(nom,x);
        cur:=cur+(2*x)-(2*y);
      end;
    end;
    ans:=max(ans,abs(cur));
    if p2[i-l]<>0 then del2(p2[i-l],nom,x);
    if p1[i-l]<>0 then
    begin
      del1(p1[i-l],nom,x);
      cur:=cur+x;
    end
    else cur:=cur-a[i-l];
    if a[i]>0 then add2(i,a[i]);
    cur:=cur+a[i];
  end;
  writeln(ans);

end.