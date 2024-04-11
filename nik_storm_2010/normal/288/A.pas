var
    n,k,i:longint;


begin

  readln(n,k);
  if (n<k) or ((n>1) and (k=1)) then begin writeln(-1); halt; end;
  if (n=1) and (k=1) then begin writeln('a'); halt; end;
  for i:=1 to n-k+2 do
    if i mod 2=1 then write('a') else write('b');
  for i:=1 to k-2 do write(chr(98+i));

end.