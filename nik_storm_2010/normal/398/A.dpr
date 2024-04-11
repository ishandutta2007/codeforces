var
  a,b,ans,cur,l,o1,o2,x1,x2:int64;
  i,j,nom:longint;

procedure printx;
begin
  if (x1<>0) then
  begin
    for i:=1 to l do write('x');
    dec(x1);
  end
  else
  begin
    for i:=1 to l+1 do write('x');
    dec(x2);
  end;
end;

procedure printo;
begin
  if (o1<>0) then
  begin
    for i:=1 to a-nom+2 do write('o');
    dec(o1);
  end
  else
  begin
    write('o');
    dec(o2);
  end;
end;

begin
  readln(a,b);
  if (b=0) then
  begin
    writeln(a*a);
    for i:=1 to a do write('o');
    halt;
  end;
  if (a=0) then
  begin
    writeln(-b*b);
    for i:=1 to b do write('x');
    halt;
  end;
  ans:=-int64(maxlongint)*maxlongint;
  for i:=1 to a do
  begin
    if (i>b) then break;
    o1:=1;
    o2:=i-1;
    cur:=int64(a-i+1)*(a-i+1)+o2;
    j:=i+1;
    l:=b div j;
    x2:=b mod j;
    x1:=j-x2;
    cur:=cur-l*l*x1-(l+1)*(l+1)*x2;
    if (cur>ans) then begin ans:=cur; nom:=i; end;
  end;
  writeln(ans);
  o1:=1;
  o2:=nom-1;
  inc(nom);
  l:=b div nom;
  x2:=b mod nom;
  x1:=nom-x2;
  printx;
  while (true) do
  begin
    if (o1+o2<>0) then printo;
    if (x1+x2<>0) then printx;
    if (o1+o2+x1+x2=0) then break;
  end;
end.