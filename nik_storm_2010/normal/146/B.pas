var
 a,b,c:longint;



procedure mask(a:longint; var c:longint);
var d,i,r,error:longint; s:string[20];
 begin
  c:=0; str(a,s);
   d:=length(s);
    for i:=1 to d do
     if (s[i]='4') or (s[i]='7')
      then
       begin
        val(s[i],r,error);
        c:=c*10+r;
       end;
 end;


begin

  readln(a,b);
   while true do
    begin
     inc(a);
      mask(a,c);
     if b=c then break;
    end;
  writeln(a);

end.