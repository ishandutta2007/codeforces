program storm;
var a:array[1..3100] of longint;
    i,ot,n:longint;


procedure inputdata;
var i,chiclo:longint;
begin
 readln(n);
 for i:=1 to n do
  begin
  read(chiclo);
  a[chiclo]:=1;
  end;
end;

procedure outputdata;
begin
 writeln(ot);
end;

begin
 inputdata;
 for i:=1 to 5000 do
  if a[i]<>1 then
    begin
     ot:=i;
     outputdata;
     halt;
    end;
end.