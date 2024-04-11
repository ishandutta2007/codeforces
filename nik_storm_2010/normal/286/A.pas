var
    a:array[1..100000] of longint; n,i:longint;


begin

  readln(n);
  if n mod 4>1 then begin writeln(-1); halt; end;
  for i:=1 to n div 2 do
    if i mod 2=1 then
    begin
      a[i]:=i+1;
      a[n-i+1]:=n-i;
    end
      else
    begin
      a[i]:=n-i+2;
      a[n-i+1]:=i-1;
    end;
  if n mod 2=1 then a[n div 2+1]:=n div 2+1;
  for i:=1 to n do write(a[i],' ');

end.