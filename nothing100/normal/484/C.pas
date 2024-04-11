var
  s,tmppp:ansistring;
  ans:array [1..1000000] of longint;
  tmp,tmpp:array [1..1000000] of longint;
  n,m:longint;
procedure get(x,y:longint);
var
  i,o,p:longint;
begin
  p:=0;
  for i:=1 to y do
  begin
    o:=i;
    while o<=x do
    begin
      inc(p);
      tmp[p]:=o;
      o:=o+y;
    end;
  end;
end;
procedure change(x,y:longint);
var
  i,o,p:longint;
begin
  for i:=1 to n do ans[i]:=i;
  for i:=1 to n do tmp[i]:=i;
  o:=1; p:=1;
  while o<=n-x+1 do
  begin
    if o=1 then get(x,y)
    else
    begin
      for i:=1 to n do tmpp[i]:=tmp[i];
      for i:=(o shr 1+1) to n do tmp[i]:=tmpp[tmpp[i-(o shr 1+1)+1]+(o shr 1+1)-1];
    end;
    if (n-x+1) and o<>0 then
    begin
      for i:=1 to n do tmpp[i]:=ans[i];
      for i:=p to n do ans[i]:=tmpp[tmp[i-p+1]+p-1];
      p:=p+o;
    end;
    o:=o shl 1;
  end;
end;
procedure init;
var
  i,j,o,p:longint;
begin
  readln(s);
  n:=length(s);
  read(m);
  for i:=1 to m do
  begin
    read(o,p);
    change(o,p);
    tmppp:=s;
    for j:=1 to n do s[j]:=tmppp[ans[j]];
    writeln(s);
  end;
end;
begin
  init;
end.