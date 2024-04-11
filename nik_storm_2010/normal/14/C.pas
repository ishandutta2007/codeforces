const
  l=4;
var
  x1,y1,x2,y2:array[1..l] of longint;
  used:array[1..l] of boolean;
  path:array[1..l] of longint;
  i,help:longint;
  good:boolean;

procedure gen(nom:longint);
var
  i:longint;
begin
  if (nom>l) then
  begin
    if (y1[path[1]]<>y2[path[1]]) then exit;
    if (y1[path[3]]<>y2[path[3]]) then exit;
    if (x1[path[2]]<>x2[path[2]]) then exit;
    if (x1[path[4]]<>x2[path[4]]) then exit;
    if (x2[path[1]]<>x1[path[2]]) then exit;
    if (x2[path[3]]<>x1[path[2]]) then exit;
    if (x1[path[1]]<>x1[path[4]]) then exit;
    if (x1[path[3]]<>x1[path[4]]) then exit;
    if (y1[path[2]]<>y1[path[1]]) then exit;
    if (y2[path[2]]<>y1[path[3]]) then exit;
    if (y1[path[4]]<>y1[path[1]]) then exit;
    if (y2[path[4]]<>y1[path[3]]) then exit;
    writeln('YES');
    halt;
  end;
  for i:=1 to l do if (not used[i]) then
  begin
    path[nom]:=i;
    used[i]:=true;
    gen(nom+1);
    used[i]:=false;
  end;
end;

begin
  good:=true;
  for i:=1 to l do
  begin
    read(x1[i],y1[i],x2[i],y2[i]);
    if (x1[i]>x2[i]) then begin help:=x1[i]; x1[i]:=x2[i]; x2[i]:=help; end;
    if (y1[i]>y2[i]) then begin help:=y1[i]; y1[i]:=y2[i]; y2[i]:=help; end;
    if (x1[i]<>x2[i]) and (y1[i]<>y2[i]) then good:=false;
    if (x1[i]=x2[i]) and (y1[i]=y2[i]) then good:=false;
  end;
  if (not good) then begin writeln('NO'); halt; end;
  gen(1);
  writeln('NO');
end.