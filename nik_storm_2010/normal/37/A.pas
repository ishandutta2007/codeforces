program storm;
var max,tek,kol,i,j,n:longint;
    a:array[1..1500] of longint;


procedure inputdata;
var i:longint;
begin
 readln(n);
 for i:=1 to n do read(a[i]);
end;

procedure outputdata;
begin
 writeln(max,' ',kol);
end;

begin
 inputdata; max:=0; kol:=0;
 for i:=1 to n do
  if a[i]<>0 then
   begin
   inc(kol); tek:=1;
   for j:=i+1 to n do
    if a[i]=a[j] then begin inc(tek); a[j]:=0; end;
   a[i]:=0;
   if tek>max then max:=tek;
   end;
 outputdata;
end.