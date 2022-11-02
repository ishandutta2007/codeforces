var
countp:array[1..20] of int64;
countn:array[1..20] of int64;
countz:int64;
n,i:longint;
total:int64;
temp:longint;

begin
readln(n);
for i:=1 to n do
begin
  read(temp);
  if temp=0 then
    inc(countz)
  else if temp>0 then
    inc(countp[temp])
  else
    inc(countn[-temp]);
end;
for i:=1 to 10 do
begin
  total:=total+countp[i]*countn[i];
//  writeln(countp[i],' ',countn[i]);
end;
total:=total+((countz*(countz-1)) div 2);
writeln(total);
end.