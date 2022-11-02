var
  k,b,n,t,x,y:int64; i:longint;


begin
  readln(k,b,n,t);
  x:=1;
  for i:=1 to n do
  begin
    y:=k*x+b;
    if (x<=t) and (t<y) then begin writeln(n-i+1); halt; end;
    x:=y;
  end;
  writeln(0);
end.