uses math;
var
    a:array[0..1439] of longint; answer,n,h,m,i:longint;


begin

  readln(n); answer:=0;
  for i:=1 to n do
    begin
      readln(h,m); inc(a[h*60+m]);
      answer:=max(answer,a[h*60+m]);
    end;
  writeln(answer);

end.