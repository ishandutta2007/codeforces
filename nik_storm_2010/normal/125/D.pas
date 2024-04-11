const max=30000;
var
  a,b,c:array[1..max] of longint; used:array[1..max] of boolean; k1,k2,n,i:longint;


function good:boolean;
var i:longint;
begin
  good:=true; k2:=0;
  for i:=1 to n do if used[i] then
  begin
    if k2<2 then begin inc(k2); c[k2]:=a[i]; end else
    if a[i]-c[k2]<>c[2]-c[1] then exit(false) else
    begin
      inc(k2); c[k2]:=a[i];
    end;
  end;
end;


procedure solution;
var i:longint;
begin
  for i:=4 to n do if a[i]-b[k1]<>b[2]-b[1] then used[i]:=true else
  begin
    inc(k1); b[k1]:=a[i];
    used[i]:=false;
  end;
  if good then
  begin
    if k1=n then used[n]:=true;
    for i:=1 to n do if used[i]=false then write(a[i],' '); writeln;
    for i:=1 to n do if used[i]=true then write(a[i],' '); halt;
  end
    else
  begin
    for i:=n downto 1 do if used[i]=false then
    begin
      used[i]:=true;
      break;
    end;
    if good then
    begin
      for i:=1 to n do if used[i]=false then write(a[i],' '); writeln;
      for i:=1 to n do if used[i]=true then write(a[i],' '); halt;
    end;
  end;
end;


begin

  readln(n); for i:=1 to n do read(a[i]);
  if n=2 then begin writeln(a[1]); writeln(a[2]); halt; end;
  fillchar(used,sizeof(used),false); used[3]:=true;
  k1:=2; b[1]:=a[1]; b[2]:=a[2]; solution;
  fillchar(used,sizeof(used),false); used[2]:=true;
  k1:=2; b[1]:=a[1]; b[2]:=a[3]; solution;
  fillchar(used,sizeof(used),false); used[1]:=true;
  k1:=2; b[1]:=a[2]; b[2]:=a[3]; solution;
  if a[2]-a[1]=a[3]-a[2] then
  begin
    fillchar(used,sizeof(used),false);
    k1:=3; b[1]:=a[1]; b[2]:=a[2]; b[3]:=a[3]; solution;
  end;
  writeln('No solution');

end.