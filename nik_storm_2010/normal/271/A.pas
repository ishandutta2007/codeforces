var
    used:array[0..9] of boolean; i,y:longint;


function good(i:longint):boolean;
var c:longint;
begin
  fillchar(used,sizeof(used),false); good:=true;
  while i<>0 do
    begin
      c:=i mod 10; i:=i div 10;
      if used[c]=true then exit(false);
      used[c]:=true;
    end;
end;


begin

  readln(y);
  for i:=y+1 to 9999 do if good(i) then
    begin
      writeln(i);
      halt;
    end

end.