const
  l=255;
var
  s:array[1..l] of string;
  rt:array[1..l] of longint;
  used:array[1..4,1..l] of boolean;
  nom:array[1..4,1..l] of longint;
  n,m,x,a,b,c,i,j,help:longint;
  ss,h:string;
  cur:char;

function unknown:longint;
var
  y:longint;
begin
  y:=(x*a+b) mod c;
  x:=y;
  unknown:=x;
end;

function find(n,num:longint):string;
var
  i,j,k:longint;
begin
  k:=0;
  for i:=1 to m do if (used[n,i]=false) then inc(k);
  j:=num mod k;
  for i:=1 to m do
  begin
    if (used[n,i]) then continue;
    if (j=0) then begin used[n,i]:=true; find:=s[nom[n,i]]; exit; end;
    dec(j);
  end;
end;

begin
  assign(input,'input.txt');
  reset(input);
  assign(output,'output.txt');
  rewrite(output);
  readln(n);
  readln(x,a,b,c);
  for i:=1 to n do
  begin
    readln(ss);
    j:=1;
    while (ss[j]<>' ') do begin s[i]:=s[i]+ss[j]; inc(j); end;
    h:='';
    for help:=j+1 to length(ss) do h:=h+ss[help];
    val(h,rt[i],help);
  end;
  for i:=1 to n do for j:=i+1 to n do if (rt[i]<rt[j]) then
  begin
    help:=rt[i]; rt[i]:=rt[j]; rt[j]:=help;
    ss:=s[i]; s[i]:=s[j]; s[j]:=ss;
  end;
  m:=n div 4; j:=0;
  for i:=1 to m do begin inc(j); nom[1,i]:=j; end;
  for i:=1 to m do begin inc(j); nom[2,i]:=j; end;
  for i:=1 to m do begin inc(j); nom[3,i]:=j; end;
  for i:=1 to m do begin inc(j); nom[4,i]:=j; end;
  for cur:='A' to chr(64+m) do
  begin
    writeln('Group ',cur,':');
    writeln(find(1,unknown));
    writeln(find(2,unknown));
    writeln(find(3,unknown));
    writeln(find(4,unknown));
  end;
  close(input);
  close(output);
end.