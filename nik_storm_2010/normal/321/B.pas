uses math;
var
  a,b,c:array[1..1000] of longint; used:array[1..1000] of boolean;
  ans,k1,k2,i,j,m,n,value,cur:longint; c1,c2,c3:char; may,good:boolean;


procedure sorta;
var i,j,w:longint;
begin
  for i:=1 to m do
    for j:=i+1 to m do
    if a[i]>a[j] then
    begin
      w:=a[i]; a[i]:=a[j]; a[j]:=w;
    end;
end;


procedure sortb;
var i,j,w:longint;
begin
  for i:=1 to k1 do
    for j:=i+1 to k1 do
    if b[i]>b[j] then
    begin
      w:=b[i]; b[i]:=b[j]; b[j]:=w;
    end;
end;


procedure sortc;
var i,j,w:longint;
begin
  for i:=1 to k2 do
    for j:=i+1 to k2 do
    if c[i]>c[j] then
    begin
      w:=c[i]; c[i]:=c[j]; c[j]:=w;
    end;
end;


function solve(nom:longint):longint;
var i,res:longint; may:boolean;
begin
  fillchar(used,sizeof(used),false); res:=0;
  for i:=nom downto 1 do
  begin
    may:=false;
    for j:=m downto 1 do
    if (used[j]=false) and (a[j]>=b[i]) then
    begin
      used[j]:=true; res:=res+a[j]-b[i]; may:=true;
      break;
    end;
    if may=false then begin solve:=-1; exit; end;
  end;
  solve:=res;
end;


begin

  readln(n,m); k1:=0; k2:=0;
  for i:=1 to n do
  begin
    read(c1,c2,c3); readln(value);
    if (c1='A') then begin inc(k1); b[k1]:=value; end
    else begin inc(k2); c[k2]:=value; end;
  end;
  for i:=1 to m do readln(a[i]);
  sorta; sortb; sortc;
  ans:=0;
  for i:=1 to k1 do
  begin
    cur:=solve(i);
    ans:=max(cur,ans);
  end;
  /// solve
  cur:=0;
  fillchar(used,sizeof(used),false);
  may:=true;
  for i:=1 to k2 do
  begin
    good:=false;
    for j:=1 to m do
    if (used[j]=false) and (a[j]>c[i]) then begin used[j]:=true; good:=true; break; end;
    if good=false then begin may:=false; break; end;
  end;
  if may=false then begin writeln(ans); halt; end;
  for i:=1 to k1 do
  begin
    good:=false;
    for j:=1 to m do
    if (used[j]=false) and (a[j]>=b[i]) then begin used[j]:=true; good:=true; cur:=cur+a[j]-b[i]; break; end;
    if good=false then begin may:=false; break; end;
  end;
  if may=false then begin writeln(ans); halt; end;
  for j:=1 to m do if used[j]=false then cur:=cur+a[j];
  ans:=max(ans,cur);
  writeln(ans);

end.