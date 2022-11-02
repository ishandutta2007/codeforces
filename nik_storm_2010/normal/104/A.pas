Program A104;
Var
  n,nado : LongInt;


BEGIN

  readln(n);
  nado:=n-10;

  if nado<1  then begin writeln(0);  halt; end;
  if nado=10 then begin writeln(15); halt; end;
  if nado>11 then begin writeln(0);  halt; end;

  writeln(4);

END.