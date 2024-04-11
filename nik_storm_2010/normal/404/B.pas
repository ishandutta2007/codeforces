var
  a,d,x,y,ost,have:extended;
  n,i:longint;
  dir:longint;

begin
  readln(a,d);
  d:=d-4*a*trunc(d/(4*a));
  readln(n);
  dir:=1;
  x:=0; y:=0;
  for i:=1 to n do
  begin
    ost:=d;
    while (ost<>0) do
    begin
      if (dir=1) then have:=a-x;
      if (dir=2) then have:=a-y;
      if (dir=3) then have:=x;
      if (dir=4) then have:=y;
      if (ost>=have) then
      begin
        if (dir=1) then x:=a;
        if (dir=2) then y:=a;
        if (dir=3) then x:=0;
        if (dir=4) then y:=0;
        inc(dir);
        if (dir=5) then dir:=1;
        ost:=ost-have;
      end
      else
      begin
        if (dir=1) then x:=x+ost;
        if (dir=2) then y:=y+ost;
        if (dir=3) then x:=x-ost;
        if (dir=4) then y:=y-ost;
        ost:=0;
      end;
    end;
    writeln(x:0:4,' ',y:0:4);
  end;
end.