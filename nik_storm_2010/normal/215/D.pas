uses math;
 var
     x,y,n,m,gold,cost,answer,sum1,sum2:int64; i:longint;


begin

  readln(n,m); answer:=0;
  for i:=1 to n do
    begin
      readln(x,y,gold,cost);
      if (x>=y) then
        begin
          answer:=answer + (cost+m*gold);
        end
          else
        begin
          if m<=(y-x) then sum1:=cost else sum1:=cost + (m*gold);
            sum2:=cost*(m div (y-x)); if m mod (y-x)<>0 then inc(sum2,cost);
          answer:=answer+min(sum1,sum2);
        end;
    end;
  writeln(answer);

end.