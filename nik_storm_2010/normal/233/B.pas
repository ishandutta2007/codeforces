uses math;
var
    ans,n,d:int64; x1,x2:extended; i,xx,ss:longint;


procedure sum(tek:longint; var s:longint);
begin
  s:=0;
  while tek<>0 do
    begin
      s:=s+(tek mod 10);
      tek:=tek div 10;
    end;
end;


begin

  readln(n); ans:=maxlongint;
  for i:=1 to 100 do
    begin
      d:=i*i-(4*(-n));
      if d>0 then
        begin
          x1:=(-i+sqrt(d))/2;
          if (frac(x1)=0) and (x1>0) then
            begin
              sum(trunc(x1),xx);
              if (xx=i) then ans:=min(ans,trunc(x1));
            end;
          x2:=(-i-sqrt(d))/2;
          if (frac(x2)=0) and (x2>0) then
            begin
              sum(trunc(x2),xx);
              if (xx=i) then ans:=min(ans,trunc(x2));
            end;
        end;
    end;
  if ans=maxlongint then writeln(-1) else writeln(ans);

end.