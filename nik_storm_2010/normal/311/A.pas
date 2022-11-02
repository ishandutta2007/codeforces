uses math;
var
    n,k,i,j,tot:longint; x,y:array[1..10000] of int64; d:extended;


begin

  readln(n,k);
  for i:=1 to n do begin x[i]:=0; y[i]:=i; end;
  tot:=0; d:=1000000000;
  for i:=1 to n do
    for j:=i+1 to n do
    begin
      inc(tot);
      if (x[j]-x[i]>=d) then break;
      d:=min(d,sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
    end;
  if tot>k then
    begin
      for i:=1 to n do writeln(x[i],' ',y[i]);
    end
      else
    begin
      writeln('no solution');
    end;


end.