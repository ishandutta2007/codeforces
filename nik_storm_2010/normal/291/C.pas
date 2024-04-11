type mas=array[1..4] of longint; const con:array[1..8] of longint=(128,64,32,16,8,4,2,1);
var
    a,b:array[1..100000] of mas; c:mas; ss,s:string;
      code,kol,j1,j2,j3,i,j,x,y,d,n,k,c1,c2,c3,c4:longint;


function check(m1,m2:mas):integer;
var i:longint;
begin
  for i:=1 to 4 do
    begin
      if m1[i]<m2[i] then exit(-1);
      if m1[i]>m2[i] then exit(+1);
    end;
  check:=0;
end;


procedure quicksort(l,r:longint);
var i,j:longint; d,w:mas;
begin
  i:=l; j:=r; d:=b[random(r-l+1)+l];
  while i<=j do
    begin
      while check(b[i],d)=-1 do inc(i);
      while check(b[j],d)=+1 do dec(j);
      if i<=j then
        begin
          w:=b[i]; b[i]:=b[j]; b[j]:=w;
          inc(i); dec(j);
        end;
    end;
  if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
end;


begin

  readln(n,k); randomize;
  for i:=1 to n do
  begin
    readln(s); d:=length(s); j:=1;
    while j<=d do
      begin
        if s[j]='.' then begin j1:=j2; j2:=j3; j3:=j; end;
        inc(j);
      end;
    ss:=copy(s,1,j1-1); val(ss,a[i,1],code);
    ss:=copy(s,j1+1,j2-j1-1); val(ss,a[i,2],code);
    ss:=copy(s,j2+1,j3-j2-1); val(ss,a[i,3],code);
    ss:=copy(s,j3+1,d-j3); val(ss,a[i,4],code);
  end;
  c[1]:=0; c[2]:=0; c[3]:=0; c[4]:=0;
  for i:=1 to 4 do
    for j:=1 to 8 do
    begin
      c[i]:=c[i]+con[j];
      for x:=1 to n do for y:=1 to 4 do b[x,y]:=a[x,y] and c[y];
      quicksort(1,n);
      kol:=1;
      for x:=2 to n do
        if check(b[x],b[x-1])<>0 then inc(kol);
      if k=kol then begin writeln(c[1],'.',c[2],'.',c[3],'.',c[4]); halt; end;
    end;
  writeln(-1);

end.