var s : string;
ok : boolean;
mask,i : longint;
begin
readln(s);
ok := true;
mask := 0;
if length(s) < 5 then ok := false;
for i := 1 to length(s) do begin
if s[i ]in ['A' .. 'Z'] then mask := mask or 1;
if s[i ]in ['a' .. 'z'] then mask := mask or 2;
if s[i ]in ['0' .. '9'] then mask := mask or 4;

end;
if mask <> 7 then ok := false;
if ok then writeln('Correct') else writeln('Too weak');
end.