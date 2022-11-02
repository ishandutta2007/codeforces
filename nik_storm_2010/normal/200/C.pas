type
  command=record
    team:string;
    point,get,miss,cnt:longint;
  end;
var
  t:array[1..4] of command;
  n1,n2,i,j,d,c1,c2,code,p1,p2,cnt,size:longint;
  hash,s1,s2:string;

function better(c1,c2:command):boolean;
var
  p1,p2:longint;
begin
  p1:=c1.point;
  p2:=c2.point;
  if (p1>p2) then begin better:=true; exit; end;
  if (p1<p2) then begin better:=false; exit; end;
  p1:=c1.get-c1.miss;
  p2:=c2.get-c2.miss;
  if (p1>p2) then begin better:=true; exit; end;
  if (p1<p2) then begin better:=false; exit; end;
  p1:=c1.get;
  p2:=c2.get;
  if (p1>p2) then begin better:=true; exit; end;
  if (p1<p2) then begin better:=false; exit; end;
  if (c1.team<c2.team) then better:=true else better:=false;
end;

procedure add(s:string;p,g,m:longint);
var
  nom,i:longint;
begin
  nom:=-1;
  for i:=1 to size do if (t[i].team=s) then nom:=i;
  if (nom=-1) then begin inc(size); t[size].team:=s; nom:=size; end;
  t[nom].point:=t[nom].point+p;
  t[nom].get:=t[nom].get+g;
  t[nom].miss:=t[nom].miss+m;
  inc(t[nom].cnt);
end;

begin
  for i:=1 to 5 do
  begin
    readln(hash);
    d:=length(hash);
    s1:=''; s2:='';
    j:=1;
    while (hash[j]<>' ') do begin s1:=s1+hash[j]; inc(j); end;
    inc(j);
    while (hash[j]<>' ') do begin s2:=s2+hash[j]; inc(j); end;
    inc(j);
    val(hash[j],c1,code);
    val(hash[j+2],c2,code);
    if (c1=c2) then begin p1:=1; p2:=1; end;
    if (c1>c2) then begin p1:=3; p2:=0; end;
    if (c1<c2) then begin p1:=0; p2:=3; end;
    add(s1,p1,c1,c2);
    add(s2,p2,c2,c1);
  end;
  for i:=1 to 4 do if (t[i].cnt<>3) then if (n1=0) then n1:=i else n2:=i;
  if (t[n1].team<>'BERLAND') then begin code:=n1; n1:=n2; n2:=code; end;
  t[n1].point:=t[n1].point+3;
  for i:=1 to 100 do for j:=0 to 100 do
  begin
    t[n1].get:=t[n1].get+j+i;
    t[n1].miss:=t[n1].miss+j;
    t[n2].get:=t[n2].get+j;
    t[n2].miss:=t[n2].miss+j+i;
    cnt:=0;
    for d:=1 to 4 do if (d<>n1) and (better(t[d],t[n1])) then inc(cnt);
    if (cnt<=1) then begin writeln(i+j,':',j); halt; end;
    t[n1].get:=t[n1].get-j-i;
    t[n1].miss:=t[n1].miss-j;
    t[n2].get:=t[n2].get-j;
    t[n2].miss:=t[n2].miss-j-i;
  end;
  writeln('IMPOSSIBLE');
end.