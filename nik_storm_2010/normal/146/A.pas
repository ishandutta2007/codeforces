var
 sum1,sum2,n,i,r:longint;
  s:string;



begin

  readln(n);sum1:=0; sum2:=0;
   readln(s);
    for i:=1 to n do
     if (s[i]<>'4') and (s[i]<>'7') then begin writeln('NO'); halt; end;
   for i:=1 to n div 2 do
    begin
      r:=ord(s[i])-48;
     sum1:=sum1+r;
    end;
   for i:=n div 2+1 to n do
    begin
      r:=ord(s[i])-48;
     sum2:=sum2+r;
    end;
  if sum1=sum2 then writeln('YES') else writeln('NO');
end.