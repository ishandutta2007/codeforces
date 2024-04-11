program storm;
var a:array[1..5,1..5] of char;


procedure inputdata;
var i,j:longint;
    s:string;
begin
 for i:=1 to 3 do
  begin
   readln(s);
   for j:=1 to 3 do a[i,j]:=s[j];
  end;
end;

procedure outputdata(priz:longint);
begin
 if priz=1 then writeln('YES')
           else writeln('NO');
end;

begin
 inputdata;
 if (a[1,1]=a[3,3]) and (a[1,2]=a[3,2]) and (a[1,3]=a[3,1]) and (a[2,1]=a[2,3])
    then  outputdata(1)
    else  outputdata(0);
end.