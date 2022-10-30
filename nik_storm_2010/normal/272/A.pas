var
    a:array[1..101] of longint; friend,answer,n,i:longint;


procedure find(var nom:longint);
var i,sum:longint;
begin
  sum:=0; for i:=1 to n+1 do sum:=sum+a[i];
  i:=1;
  while sum<>1 do
    begin
      dec(sum); inc(i);
      if i=n+2 then i:=1;
    end;
  nom:=i;
end;


begin

  readln(n); for i:=2 to n+1 do read(a[i]);
  answer:=0;
  for i:=1 to 5 do
    begin
      a[1]:=i; find(friend);
      if friend<>1 then inc(answer);
    end;
  writeln(answer);

end.