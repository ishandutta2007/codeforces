var
    n,b,i:longint; need,tek:extended;
     a:array[1..100] of longint;


begin

  readln(n,b);
   for i:=1 to n do
    begin
     read(a[i]);
     b:=b+a[i];
    end;

  need:=(b/n);
   for i:=1 to n do
  if a[i]>need then begin writeln(-1); halt; end;

  for i:=1 to n do
   begin
    tek:=need-a[i];
    writeln(tek:0:6);
   end;

end.