var
    a:array[1..100] of longint; ans,tek,n,i,j:longint;


procedure check(l,r:longint; var tek:longint);
var i:longint;
begin
  tek:=0;
  for i:=l to r do tek:=tek xor a[i];
end;


begin

  readln(n); for i:=1 to n do read(a[i]);
  ans:=0;
  for i:=1 to n do
    for j:=i to n do
    begin
      check(i,j,tek);
      if tek>ans then ans:=tek;
    end;
  writeln(ans);

end.