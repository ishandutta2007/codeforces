program storm;
var a:set of 'a' .. 'z';
    b:set of 'A' .. 'Z';
    ch,mal,bol,priz,d,i:longint;
    s:string;

procedure inputdata;
begin
 readln(s);
end;

procedure outputdata;
begin
 writeln(s);
end;

begin
 inputdata;
 d:=length(s);  mal:=0; bol:=0;
 for i:=1 to d do
  begin
   ch:=ord(s[i]);
   if (ch>=97) and (ch<=122) then inc(mal)
                             else inc(bol);
  end;
 if mal>=bol then priz:=1
             else priz:=0;
 if priz=1 then
   begin
    for i:=1 to d do
     begin
     ch:=ord(s[i]);
     if (ch>=97) and (ch<=122) then
                               else s[i]:=chr(ch+32);
     end;
   end
            else
   begin
    for i:=1 to d do
     begin
     ch:=ord(s[i]);
     if (ch>=97) and (ch<=122) then s[i]:=chr(ch-32);
     end;
   end;
 outputdata;
end.