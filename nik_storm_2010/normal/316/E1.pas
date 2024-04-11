const module=1000000000;
var
    f,a:array[0..200000] of int64; n,m,i,j,t,x,y,z:longint; sum:int64;


begin

  readln(n,m); for i:=1 to n do read(a[i]);
  f[0]:=1; f[1]:=1;
  for i:=2 to n do f[i]:=(f[i-1]+f[i-2]) mod module;
  for i:=1 to m do
  begin
    read(t);
    if t=1 then begin readln(x,y); a[x]:=y; end;
    if t=2 then
    begin
      readln(x,y); sum:=0;
      for j:=x to y do sum:=(sum+(a[j]*f[j-x])) mod module;
      writeln(sum);
    end;
    if t=3 then
    begin
      readln(x,y,z);
      for j:=x to y do a[j]:=(a[j]+z) mod module;
    end;
  end;

end.