var
  h:array[1..2,'0'..'9'] of longint; s:string; ans,d,i:longint;


function have:boolean;
var i:char;
begin
  for i:='0' to '9' do if h[1,i]>h[2,i] then exit(false);
  have:=true;
end;


procedure modify;
var i:char;
begin
  for i:='0' to '9' do dec(h[2,i],h[1,i]);
end;


procedure f(nom:longint;c:char);
begin
  if (c='2') or (c='5') then inc(h[nom,'2']) else
  if (c='6') or (c='9') then inc(h[nom,'6']) else
  inc(h[nom,c]);
end;


begin

  readln(s); d:=length(s); for i:=1 to d do f(1,s[i]);
  readln(s); d:=length(s); for i:=1 to d do f(2,s[i]);
  while have do
  begin
    modify; inc(ans);
  end;
  writeln(ans);

end.