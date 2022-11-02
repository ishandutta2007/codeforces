var
    a,b:array[1..300000] of int64; sum,kol,n,t,x,d:int64; i:longint;


begin

  readln(n); sum:=0; kol:=1;
  for i:=1 to n do
    begin
      read(t);
      if t=1 then
        begin
          readln(x,d); b[x]:=b[x]+d; sum:=sum+x*d;
          writeln(sum/kol:0:6);
        end
          else
        begin
          if t=2 then
            begin
              readln(x); inc(kol); a[kol]:=x; sum:=sum+x;
              writeln(sum/kol:0:6);
            end
              else
            begin
              readln; sum:=sum-(a[kol]+b[kol]);
              b[kol-1]:=b[kol-1]+b[kol]; b[kol]:=0; dec(kol);
              writeln(sum/kol:0:6);
            end;
        end;
    end;

end.