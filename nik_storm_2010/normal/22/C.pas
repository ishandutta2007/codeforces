var
  n,m,v,x,y,res:int64;
  i,j:longint;

begin
  readln(n,m,v);
  if (m<n-1) then begin writeln(-1); halt; end;
  x:=n-2;
  res:=(x*(x-1)) div 2+n-1;
  if (v<=x) then inc(x);
  if (m>res) then begin writeln(-1); halt; end;
  for i:=1 to n do if (i<>v) then writeln(i,' ',v);
  m:=m-n+1;
  for i:=1 to x do
  begin
    if (i=v) then continue;
    if (m=0) then break;
    for j:=i+1 to x do
    begin
      if (j=v) then continue;
      dec(m);
      writeln(i,' ',j);
      if (m=0) then break;
    end;
  end;
end.