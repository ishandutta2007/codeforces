var
    answer,p,i:longint;


function maybe(nom:longint):boolean;
var step,tek,i:longint;
begin
  tek:=nom; step:=1;
  while step<>p-1 do
    begin
      if tek=1 then exit(false); inc(step);
      tek:=(tek*nom) mod p;
    end;
  if tek<>1 then exit(false) else exit(true);
end;


begin

  readln(p); answer:=0;
  for i:=1 to p-1 do
    if maybe(i)=true then inc(answer);
  writeln(answer);

end.