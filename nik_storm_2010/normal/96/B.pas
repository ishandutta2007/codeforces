program B96;
var
  s : shortstring;
  long,code,c:longint;



function prov(s:shortstring) : boolean;
var kol4,kol7,i:longint;
 begin
   kol4:=0;
    kol7:=0;
     for i:=1 to long do
      if s[i]='4'
       then inc(kol4)
       else inc(kol7);

   if kol4=kol7 then prov:=true
                else prov:=false;

 end;


procedure outputdata(s:shortstring);
 begin
  writeln(s);
   halt;
 end;



procedure rec(s:shortstring);
var code:longint;
     ch:int64;
 begin
  if length(s)=long
   then
    begin

      val(s,ch,code);
      if (prov(s) = true) and (ch>=c) then outputdata(s);

    end
   else
    begin

      s:=s + '4';
      rec(s);
      delete(s,length(s),1);

      s:=s + '7';
      rec(s);
      delete(s,length(s),1);

    end;
 end;


procedure outputdatane;
var i:longint;
 begin
  inc(long);
   for i:=1 to long div 2 do write('4');
    for i:=1 to long div 2 do write('7');
     halt;
 end;


Begin

  readln(s);
   val(s,c,code);
    long:=length(s);

  if long mod 2 = 1 then outputdatane;

  rec('');

  inc(long,2);
  outputdatane;

End.