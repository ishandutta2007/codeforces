program storm;
const nMax = 200;
var a:array[1..nMax] of longint;
    i,n,nom,del2,nedel2:longint;


procedure inputdata;
var i:longint;
begin
 readln(n);
 for i:=1 to n do read(a[i]);
end;

procedure outputdata;
begin
 writeln(nom);
end;

begin
 inputdata;
 del2:=0; nedel2:=0; nom:=0;
 for i:=1 to n do
  if a[i] mod 2 = 0 then inc(del2)
                    else inc(nedel2);
 if del2=1 then
    begin
    for i:=1 to n do
     if a[i] mod 2 = 0 then begin nom:=i; break; end;
    end
           else
    begin
    for i:=1 to n do
     if a[i] mod 2 = 1 then begin nom:=i; break; end;
    end;
 outputdata;
end.