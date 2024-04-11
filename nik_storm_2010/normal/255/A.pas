var
    sum1,sum2,sum3,n,i,c:longint;


begin

  readln(n); sum1:=0; sum2:=0; sum3:=0;
  for i:=1 to n do
    begin
      read(c);
      if i mod 3=1 then sum1:=sum1+c else
        if i mod 3=2 then sum2:=sum2+c else
        sum3:=sum3+c;
    end;

  if (sum1>sum2) and (sum1>sum3) then writeln('chest');
  if (sum2>sum1) and (sum2>sum3) then writeln('biceps');
  if (sum3>sum1) and (sum3>sum2) then writeln('back');

end.