 var
  s,sans : string;
   d,i: longint;
    priz,priz1: boolean;



begin

  readln(s);
   d:=length(s);
    priz:=true;
     priz1:=true; sans:='';
    if ord(s[1])>=97 then priz1:=true else priz1:=false;
    if ord(s[1])>=97 then priz:=false else priz:=true;
     if (ord(s[1])>=97) then sans:=chr( ord(s[1])-32 )
                       else sans:=chr( ord(s[1]) + 32);

    for i:=2 to d do
     begin

       if ord(s[i])>=97 then begin priz:=false; priz1:=false; end;
        if (ord(s[i])>=97) then sans:=sans + chr( ord(s[i]) - 32)
                            else sans:=sans + chr( ord(s[i]) + 32);

     end;
  if (priz=true) or (priz1=true)
   then
    begin
     writeln(sans);
    end
   else
    begin
     writeln(s);
    end;

end.