program storm;
var n,kol1,kol2:longint;
    s1,s2:string;


procedure inputdata;
var i:longint;
    s:string;
begin
 readln(n);
 s1:=''; s2:=''; kol1:=0; kol2:=0;
 for i:=1 to n do
  begin
  readln(s);
  if (s1='') then begin s1:=s; inc(kol1); end else
   if (s=s1) then begin inc(kol1); end else
    if (s2='') then begin s2:=s; inc(kol2); end else
     if (s=s2) then begin inc(kol2); end;
  end;
end;

procedure outputdata(s:string);
begin
 writeln(s);
end;

begin
 inputdata;
 if kol1>kol2 then outputdata(s1)
              else outputdata(s2);
end.