var
  n,a,b,x,dollars,need:int64;
  i:longint;

begin
  readln(n,a,b);
  for i:=1 to n do
  begin
    read(x);
    write(trunc(x-trunc(x*a/b)*b/a),' ');
  end;
end.