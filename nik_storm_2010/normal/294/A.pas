var
    a:array[0..101] of longint; n,k,x,y,i:longint;


begin

  readln(n); for i:=1 to n do read(a[i]); readln;
  readln(k);
  for i:=1 to k do
    begin
      readln(x,y);
      a[x-1]:=a[x-1]+(y-1);
      a[x+1]:=a[x+1]+(a[x]-y);
      a[x]:=0;
    end;
  for i:=1 to n do writeln(a[i]);

end.