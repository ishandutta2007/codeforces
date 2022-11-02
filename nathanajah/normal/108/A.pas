var
s:string;
hstr:string;
mstr:string;
balikhstr:string;
h,m,balikh:longint;

begin
readln(s);
hstr:=copy(s,1,2);
mstr:=copy(s,4,2);
balikhstr:=hstr[2]+hstr[1];
val(hstr,h);
val(mstr,m);
val(balikhstr,balikh);
if (balikh<60) and (balikh>m) then
  writeln(hstr,':',balikhstr)
else
begin
  repeat
    h:=(h+1) mod 24;
    str(h,hstr);
    if length(hstr)=1 then hstr:='0'+hstr;
    balikhstr:=hstr[2]+hstr[1];
    val(balikhstr,balikh);
  until balikh<60;
  writelN(hstr,':',balikhstr);
end;
end.