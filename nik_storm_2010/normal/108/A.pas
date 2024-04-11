Program A108;
Var
  s,s1,s2 : string;
  hour,minute,code : longint;



Procedure prov( s:string );
 Begin
  if (s[1]=s[5]) and (s[2]=s[4]) then begin writeln(s); halt; end;
 End;


BEGIN

  readln(s);

  val(s[1]+s[2],hour,code);
  val(s[4]+s[5],minute,code);

  while true do
   begin

    while minute<>59 do
     begin
      inc(minute);
      str(minute,s1);
      str(hour,s2);
      if length(s2)=1 then s2:='0'+s2;
      if minute<10 then prov(s2+':0'+s1)
                   else prov(s2+':'+s1);
     end;

    inc(hour);
    if hour = 24 then hour:=0;
    minute:=-1;
   end;

END.