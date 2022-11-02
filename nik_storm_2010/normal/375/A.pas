var
  used:array['0'..'9'] of boolean;
  a:array[1..1000000] of longint;
  d,i,code:longint;
  s,ss:ansistring;

function check:boolean;
var
  x,i,j:longint;
begin
  j:=1; x:=0;
  for i:=d downto 1 do
  begin
    x:=(x+a[i]*j) mod 7;
    j:=(j*10) mod 7;
  end;
  if (x mod 7=0) then exit(true) else exit(false);
end;

procedure gen(nom:longint);
var
  x:longint;
begin
  if (nom=5) then
  begin
    if (not check) then exit;
    for i:=1 to d do write(a[i]);
    halt;
  end;
  if (not used['1']) then
  begin
    used['1']:=true;
    a[nom]:=1;
    gen(nom+1);
    used['1']:=false;
  end;
  if (not used['6']) then
  begin
    used['6']:=true;
    a[nom]:=6;
    gen(nom+1);
    used['6']:=false;
  end;
  if (not used['8']) then
  begin
    used['8']:=true;
    a[nom]:=8;
    gen(nom+1);
    used['8']:=false;
  end;
  if (not used['9']) then
  begin
    used['9']:=true;
    a[nom]:=9;
    gen(nom+1);
    used['9']:=false;
  end;
end;

begin
  readln(s);
  d:=length(s);
  ss:='';
  for i:=1 to d do if (s[i] in ['1','6','8','9']) and (not used[s[i]])
  then used[s[i]]:=true
  else ss:=ss+s[i];
  for i:=(d-4) downto 1 do val(ss[i],a[i+4],code);
  fillchar(used,sizeof(used),false);
  gen(1);
  writeln(0);
end.