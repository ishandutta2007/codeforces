var
s, t : string;
c : char;
i, j : longint;
ok : boolean;

begin
readln(s);
for i := 0 to length(s) do begin
for c := 'a' to 'z' do begin
t := '';
for j := 1 to i do t := t + s[j];
t := t + c;
for j := i + 1 to length(s) do t := t + s[j];
ok := true;
for j := 1 to length(t) do if t[j] <> t[length(t) - j + 1] then ok := false;
if ok then begin
writeln(t);
halt(0);
end;
end;
end;
writeln('NA');
end.