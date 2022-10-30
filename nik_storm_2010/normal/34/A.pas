program storm;
const inf = MaxLongint;
var  a:array[1..250] of longint;
     n,nom1,nom2,min,i:longint;


procedure inputdata;
var i:longint;
begin
 readln(n);
 for i:=1 to n do read(a[i]) ;
end;

procedure outputdata;
begin
 writeln(nom1,' ',nom2);
end;

begin
 inputdata; nom1:=0; nom2:=0; min:=inf;
 for i:=1 to n-1 do
  if abs(a[i]-a[i+1])<min then begin min:=abs(a[i]-a[i+1]); nom1:=i; nom2:=i+1; end;
 if abs(a[1]-a[n])<min then begin nom1:=n; nom2:=1; end;
 outputdata;
end.