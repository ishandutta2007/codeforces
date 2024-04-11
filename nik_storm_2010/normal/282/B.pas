var
    ans:array[1..1000000] of char; sum1,sum2,n,a,b,i:longint;


begin

  readln(n); sum1:=0; sum2:=0;
  for i:=1 to n do
    begin
      readln(a,b);
      if (sum1+a)-sum2<=500 then
        begin
          sum1:=sum1+a; ans[i]:='A';
        end
          else
        begin
          sum2:=sum2+b; ans[i]:='G';
        end;
    end;
  if abs(sum1-sum2)<=500 then for i:=1 to n do write(ans[i]) else
    begin
      writeln(-1);
    end;

end.