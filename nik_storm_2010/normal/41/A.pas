program storm;
var d1,d2,i:longint;
    s1,s2:string;

procedure inputdata;
begin
 readln(s1);
 readln(s2);
end;

procedure outputdata(priz:longint);
begin
 if priz=1 then writeln('YES')
           else writeln('NO');
end;

begin
 inputdata;
 d1:=length(s1); d2:=length(s2);
 if d1<>d2 then begin outputdata(0); halt; end;
 for i:=1 to d1 do
  if s1[i]=s2[d2-i+1] then
                      else begin outputdata(0); halt; end;
 outputdata(1);
end.