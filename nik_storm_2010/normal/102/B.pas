Program B102;
Var
  s : ansistring;
  d,kol : longint;


procedure inputdata;
 begin
  readln(s);
   d:=length(s);
 end;


procedure pered(s:ansistring; var s1:ansistring);
var c:int64;
     i,t,code:longint;
 begin
  c:=0;
   for i:=1 to d do
    begin
     val(s[i],t,code);
      inc(c,t);
    end;
   str(c,s1);
 end;


procedure outputdata;
 begin
  writeln(kol);
 end;


Begin

  kol:=0;
   inputdata;
    while d>1 do
     begin
      inc(kol);
       pered(s,s);
        d:=length(s);
     end;
   outputdata;

End.