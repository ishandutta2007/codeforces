uses math;
var
    a:array[1..10000] of longint; n,p,k,q,h,i,j:longint;


begin

  readln(n,k); for i:=1 to n-1 do a[i]:=1;
  h:=1;
  for i:=1 to k do
  begin
    q:=1;
    for j:=1 to n do if a[j]<>n-j then
    begin
      p:=(n-j)-a[j]; p:=min(p,h);
      a[j]:=a[j]+p; q:=max(q,a[j]);
      write(n-p,' ');
    end
    else write(n,' ');
    writeln; h:=q;
  end;

end.