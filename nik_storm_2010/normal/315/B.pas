var
    a:array[1..100000] of int64; cf,n,m,i:longint; add,x,y:int64;


begin

  readln(n,m);
  for i:=1 to n do read(a[i]); readln;
  add:=0;
  for i:=1 to m do
  begin
    read(cf);
    if cf=1 then
    begin
      readln(x,y);
      a[x]:=y-add;
    end
      else
    begin
      if cf=2 then
      begin
        readln(x); add:=add+x;
      end
        else
      begin
        readln(x); writeln(a[x]+add);
      end;
    end;
  end;

end.