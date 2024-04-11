Program B110;
Var
  i,n,k : longint;
  s : ansistring;


BEGIN

  readln(n);

  k:=96;
  for i:=1 to n do
   begin
    inc(k);
    if k=101 then k:=97;
    s:=s+chr(k);
   end;

  writeln(s);

END.