program storm;
var c:array[1..150] of longint;
    n,a,b,i,sum:longint;


procedure inputdata;
var i:longint;
begin
 readln(n);
 for i:=1 to n-1 do read(c[i]);
 readln(a,b);
end;

procedure outputdata;
begin
 writeln(sum);
end;

begin
 inputdata;
 for i:=a to b-1 do sum:=sum+c[i];
 outputdata;
end.