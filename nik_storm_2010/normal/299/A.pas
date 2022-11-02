var
    a:array[1..100000] of longint; min,n,i:longint;


begin

  readln(n); min:=maxlongint;
  for i:=1 to n do
    begin
      read(a[i]);
      if a[i]<min then min:=a[i];
    end;
  for i:=1 to n do
    if a[i] mod min<>0 then begin writeln(-1); halt; end;
  writeln(min);

end.