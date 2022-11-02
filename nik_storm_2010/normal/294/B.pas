uses math;
var
    a,f:array[1..2,0..101] of longint; ans,kol1,kol2,n,t,w,i,j:longint;


procedure bubblesort(nom,n:longint);
var i,j,w:longint;
begin
  for i:=1 to n do
    for j:=i+1 to n do
    if a[nom,i]>a[nom,j] then
    begin
      w:=a[nom,i]; a[nom,i]:=a[nom,j]; a[nom,j]:=w;
    end;
end;


begin

  readln(n); kol1:=0; kol2:=0;
  for i:=1 to n do
    begin
      readln(t,w);
      if t=1 then begin inc(kol1); a[1,kol1]:=w; end
             else begin inc(kol2); a[2,kol2]:=w; end;
    end;
  bubblesort(1,kol1); bubblesort(2,kol2);
  for i:=1 to kol1 do f[1,i]:=f[1,i-1]+a[1,i];
  for i:=1 to kol2 do f[2,i]:=f[2,i-1]+a[2,i];
  ans:=maxlongint;
  for i:=0 to kol1 do
    for j:=0 to kol2 do
    begin
      t:=(kol1-i)+2*(kol2-j);
      if t>=f[1,i]+f[2,j] then ans:=min(ans,t);
    end;
  writeln(ans);

end.