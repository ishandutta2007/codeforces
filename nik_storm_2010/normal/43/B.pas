program storm;
var s1,s2:string;
    d2,d1,i,j,priz:longint;

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
 inputdata; d2:=length(s2);
 for i:=1 to d2 do
  if s2[i]<>' '  then
  begin
  d1:=length(s1); priz:=0;
  for j:=1 to d1 do
   if s2[i]=s1[j] then begin priz:=1; delete(s1,j,1); break; end;
  if priz=0 then begin outputdata(0); halt; end;
  end;
 outputdata(1);
end.