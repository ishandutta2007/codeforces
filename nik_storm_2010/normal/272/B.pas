var
    f:array[1..32] of int64;  answer:int64; tek,n,i,c:longint;


function rec(c:longint):longint;
begin
  if c=0 then rec:=0 else
    begin
      if c mod 2=0 then rec:=rec(c div 2) else rec:=rec(c div 2)+1;
    end;
end;


begin

  readln(n);
  for i:=1 to n do
    begin
      read(c); tek:=rec(c);
      inc(f[tek]);
    end;
  answer:=0;
  for i:=1 to 32 do
    if f[i]<>0 then
    begin
      answer:=answer + (f[i]*(f[i]-1)) div 2;
    end;
  writeln(answer);

end.