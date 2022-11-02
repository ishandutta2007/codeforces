const
  l=200000;
type
  state=record x,num:longint; end;
var
  a:array[1..l] of longint;
  pmax,pmin,smin,smax:array[1..l] of state;
  n,i:longint;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  pmin[1].x:=a[1]; pmin[1].num:=1;
  pmax[1].x:=a[1]; pmax[1].num:=1;
  for i:=2 to n do
  begin
    pmin[i]:=pmin[i-1];
    pmax[i]:=pmax[i-1];
    if (a[i]<pmin[i].x) then begin pmin[i].x:=a[i]; pmin[i].num:=i; end;
    if (a[i]>pmax[i].x) then begin pmax[i].x:=a[i]; pmax[i].num:=i; end;
  end;
  smin[n].x:=a[n]; smin[n].num:=n;
  smax[n].x:=a[n]; smax[n].num:=n;
  for i:=n-1 downto 1 do
  begin
    smin[i]:=smin[i+1];
    smax[i]:=smax[i+1];
    if (a[i]<smin[i].x) then begin smin[i].x:=a[i]; smin[i].num:=i; end;
    if (a[i]>smax[i].x) then begin smax[i].x:=a[i]; smax[i].num:=i; end;
  end;
  for i:=2 to n-1 do
  begin
    if (a[i]>pmin[i-1].x) and (a[i]>smin[i+1].x) then
    begin
      writeln(3);
      writeln(pmin[i-1].num,' ',i,' ',smin[i+1].num);
      halt;
    end;
    if (a[i]<pmax[i-1].x) and (a[i]<smax[i+1].x) then
    begin
      writeln(3);
      writeln(pmax[i-1].num,' ',i,' ',smax[i+1].num);
      halt;
    end;
  end;
  writeln(0);
end.