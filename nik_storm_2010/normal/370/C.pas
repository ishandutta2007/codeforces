uses
  math;
const
  l=6000;
var
  pair:array[1..2,1..l] of longint;
  color,used:array[1..l] of longint;
  n,m,i,ans,time,x,y,big,c,num:longint;

procedure print;
var
  i:longint;
begin
  writeln(ans*2);
  for i:=1 to ans do
  begin
    writeln(pair[1,i],' ',pair[2,i]);
    writeln(pair[2,i],' ',pair[1,i]);
  end;
end;

begin
  readln(n,m);
  for i:=1 to n do
  begin
    read(c);
    inc(color[c]);
  end;
  ans:=0;
  for time:=1 to 2*l do
  begin
    big:=-1;
    x:=-1;
    for i:=1 to m do if (color[i]>big) then begin big:=color[i]; x:=i; end;
    if (big<=0) then break;
    used[x]:=time;
    big:=-1;
    for i:=1 to m do
    begin
      if (used[i]=time) then continue;
      if (color[i]>big) then begin big:=color[i]; y:=i; end;
    end;
    if (big<=0) then break;
    dec(color[x]);
    dec(color[y]);
    inc(ans);
    pair[1,ans]:=x;
    pair[2,ans]:=y;
  end;
  big:=-1;
  for i:=1 to n do if (color[i]>big) then begin big:=color[i]; x:=i; end;
  if (big<=0) then begin print; halt; end;
  num:=-1;
  for i:=1 to ans do
  begin
    if (pair[1,i]<>x) and (pair[2,i]<>x) then num:=i;
  end;
  if (num=-1) then
  begin
    print;
    for i:=1 to big do writeln(x,' ',x);
  end
  else
  begin
    writeln(ans*2+1);
    for i:=1 to ans do
    begin
      if (i=num) then
      begin
        writeln(pair[1,i],' ',pair[2,i]);
        writeln(pair[2,i],' ',x);
        writeln(x,' ',pair[1,i]);
      end
        else
      begin
        writeln(pair[1,i],' ',pair[2,i]);
        writeln(pair[2,i],' ',pair[1,i]);
      end;
    end;
    for i:=1 to big-1 do writeln(x,' ',x);
  end;
end.