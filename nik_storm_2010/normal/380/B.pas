const
  lim=10000;
var
  num:array[1..1000010] of longint;
  g:array[1..2,1..lim] of longint;
  step,l,r,z,lvl:array[0..lim] of longint;
  n,i,j,pos,c,a,b,cnt,res,time,m:longint;
  good:boolean;

function dich(x:longint):longint;
var
  l,r,m:longint;
begin
  l:=0; r:=30;
  while (r-l>1) do
  begin
    m:=(l+r) div 2;
    if (step[m]<x) then l:=m else r:=m;
  end;
  exit(l);
end;

begin
  step[1]:=1;
  for i:=2 to 30 do step[i]:=step[i-1]*2;
  readln(n,m);
  cnt:=0; time:=0;
  for i:=1 to m do
  begin
    read(c);
    if (c=1) then
    begin
      inc(cnt);
      readln(lvl[cnt],l[cnt],r[cnt],z[cnt]);
    end
    else
    begin
      inc(time);
      readln(a,b);
      fillchar(g,sizeof(g),0);
      g[1,a]:=b; g[2,a]:=b;
      for j:=a to n-1 do
      begin
        g[1,j+1]:=g[1,j]+dich(g[1,j]);
        g[2,j+1]:=g[2,j]+dich(g[2,j]+1);
      end;
      res:=0;
      for j:=1 to cnt do
      begin
        if (lvl[j]<a) then continue;
        good:=false;
        if (g[1,lvl[j]]<=l[j]) and (l[j]<=g[2,lvl[j]]) then good:=true;
        if (g[1,lvl[j]]<=r[j]) and (r[j]<=g[2,lvl[j]]) then good:=true;
        if (l[j]<=g[1,lvl[j]]) and (g[1,lvl[j]]<=r[j]) then good:=true;
        if (l[j]<=g[2,lvl[j]]) and (g[2,lvl[j]]<=r[j]) then good:=true;
        if (good) then
        begin
          if (num[z[j]]<>time) then inc(res);
          num[z[j]]:=time;
        end;
      end;
      writeln(res);
    end;
  end;
end.